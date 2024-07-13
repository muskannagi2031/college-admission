import sqlite3

def create_database():
    conn = sqlite3.connect('admission.db')
    c = conn.cursor()
    c.execute('''
        CREATE TABLE IF NOT EXISTS candidates (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            score FLOAT,
            diploma BOOLEAN NOT NULL CHECK (diploma IN (0, 1))
        )
    ''')
    conn.commit()
    conn.close()

create_database()
