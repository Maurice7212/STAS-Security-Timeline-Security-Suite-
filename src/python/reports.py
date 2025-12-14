import pandas as pd
import sqlite3

def generate_report(db_file, output_file):
    conn = sqlite3.connect(db_file)
    df = pd.read_sql_query('SELECT * FROM events', conn)
    conn.close()

    # Generate HTML
    html = df.to_html()
    with open(output_file, 'w') as f:
        f.write(f'<html><body><h1>STAS Report</h1>{html}</body></html>')

    # Add PDF via reportlab or similar if needed
    # JSON: df.to_json()
    # Markdown: df.to_markdown()