import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QLabel, QPushButton, QTextEdit
from PyQt6.QtCore import QTimer
import sqlite3
from graphviz import Source
from anomaly_detector import AnomalyDetector
from reports import generate_report

class Dashboard(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('STAS Dashboard')
        self.setStyleSheet("background-color: #333; color: #fff;")  # Dark mode

        central = QWidget()
        layout = QVBoxLayout()

        self.load_btn = QPushButton('Load Sample')
        self.load_btn.clicked.connect(self.load_sample)
        layout.addWidget(self.load_btn)

        self.event_feed = QTextEdit()
        layout.addWidget(QLabel('Live Event Feed'))
        layout.addWidget(self.event_feed)

        self.timeline = QTextEdit()
        layout.addWidget(QLabel('Timeline'))
        layout.addWidget(self.timeline)

        self.risk_label = QLabel('Risk Score: 0')
        layout.addWidget(self.risk_label)

        self.graph_preview = QLabel()  # For GraphViz PNG
        layout.addWidget(self.graph_preview)

        self.export_btn = QPushButton('Export Report')
        self.export_btn.clicked.connect(self.export_report)
        layout.addWidget(self.export_btn)

        central.setLayout(layout)
        self.setCentralWidget(central)

        # Live update timer
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_feed)
        self.timer.start(1000)

        self.ad = AnomalyDetector()

    def load_sample(self):
        # Call C++ engine via subprocess or IPC
        import subprocess
        subprocess.call(['../../build/stas_engine.exe', 'sample.exe'])
        self.update_dashboard()

    def update_feed(self):
        # Read from SQLite
        conn = sqlite3.connect('../../events.db')
        cur = conn.cursor()
        cur.execute('SELECT * FROM events ORDER BY timestamp DESC LIMIT 10')
        events = cur.fetchall()
        self.event_feed.setText('\n'.join(str(e) for e in events))
        conn.close()

    def update_dashboard(self):
        # Risk score from DB or calc
        self.risk_label.setText('Risk Score: 85')

        # Timeline
        self.timeline.setText('Event 1: Process Create\nEvent 2: File Write')

        # GraphViz
        with open('output.dot', 'r') as f:
            src = Source(f.read())
            src.render('output', format='png')
        pixmap = QPixmap('output.png')
        self.graph_preview.setPixmap(pixmap)

        # ML labels
        events = []  # Fetch from DB
        labels = self.ad.detect_anomalies(events)
        print(labels)

    def export_report(self):
        generate_report('events.db', 'report.html')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    win = Dashboard()
    win.show()
    sys.exit(app.exec())