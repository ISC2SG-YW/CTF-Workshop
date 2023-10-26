from flask import Flask, render_template, request, redirect, url_for, send_from_directory

app = Flask(__name__)
static = "./static"
user_data = [
    {
        "id": 1,
        "username": "bff149a0b87f5b0e00d9dd364e9ddaa0",
        "password": "a502ce1eff5696a67621d6368cfca455fc3648f9",
        "flag": "ISC2CTF{1D0R_!$_3@5Y}"
    },
    {
        "id": 2,
        "username": "james",
        "password": "password123",
        "flag": "No flag available."
    }
]


@app.route('/')
def home():
    return send_from_directory(static, 'login.html')

@app.route('/account/<int:user_id>')
def account(user_id):
    for user in user_data:
        if user['id'] == user_id:
            return render_template('account.html', user=user)

    return "User not found."


@app.route('/login', methods=['POST'])
def login():

    username = request.form.get('username')
    password = request.form.get('password')

    if not username or not password:
        return redirect(url_for('home'))

    for user in user_data:
        if user['username'] == username and user['password'] == password:
            return redirect(url_for('account', user_id=user['id']))

    return redirect(url_for('home'))


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000)
