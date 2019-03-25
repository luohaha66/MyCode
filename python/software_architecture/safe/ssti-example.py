# Code Listing #9

"""

SSTI - Server Side Template Injection example - using Flask

"""

# ssti-example.py
from flask import Flask
from flask import request, render_template_string, render_template

app = Flask(__name__)


@app.route('/hello-ssti')
def hello_ssti():
    person = {'name': "world", 'secret': 'jo5gmvlligcZ5YZGenWnGcol8JnwhWZd2lJZYo=='}
    if request.args.get('name'):
        person['name'] = request.args.get('name')
        print(person['name'])
        print(type(person['name']))

    # %s in function render_template_string is dangerous, because it will be eval
    template = '<h2>Hello %s!</h2>' % person['name']
    # to fix use
    # template = '<h2>Hello {{person.name}} !</h2>'
    return render_template_string(template, person=person)


# http://localhost:5000/hello-ssti?name={{person.secret}}
if __name__ == "__main__":
    app.run(debug=True)
