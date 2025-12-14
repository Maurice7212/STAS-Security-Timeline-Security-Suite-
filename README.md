# Security Timeline Analysis Suite (STAS)

A hybrid malware analysis tool.

## Build
- C++: Use CMake + MSVC.
- Python: `pip install -r requirements.txt`, then `pyinstaller --onefile dashboard.py`.

## Run
- Engine: `./stas_engine.exe <sample_path>`
- Dashboard: `python dashboard.py`