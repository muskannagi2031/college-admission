from flask import Flask, request, render_template, redirect, url_for
import sqlite3

app = Flask(__name__)

def connect_db():
    return sqlite3.connect('admission.db')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/submit', methods=['POST'])
def submit():
    name = request.form['name']
    score = float(request.form['score'])
    diploma = request.form.get('diploma', 'off') == 'on'
    
    selected = score > 70 or diploma

    conn = connect_db()
    c = conn.cursor()
    c.execute('INSERT INTO candidates (name, score, diploma) VALUES (?, ?, ?)', (name, score, diploma))
    conn.commit()
    conn.close()
    
    return redirect(url_for('result', name=name, selected=selected))

@app.route('/result')
def result():
    name = request.args.get('name')
    selected = request.args.get('selected') == 'True'
    
    conn = connect_db()
    c = conn.cursor()
    c.execute('SELECT * FROM candidates WHERE name = ?', (name,))
    candidate = c.fetchone()
    conn.close()
    
    if candidate:
        return render_template('result.html', name=candidate[1], selected=selected)
    else:
        return 'Candidate not found', 404

if __name__ == '__main__':
    app.run(debug=True)
