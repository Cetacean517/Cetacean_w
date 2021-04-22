#!/usr/bin/env python
# -*-coding:utf-8-*-
# @Time: 4/19/2021 9:09 PM
# @File: app.py
# @Author: Chasing
# @Email: chasing1020@gmail.com
# @Software: PyCharm

from flask import request, Flask, jsonify, session, json
from query import *
from reply import *

app = Flask(__name__)


@app.route('/')
def hello_world():
    return 'Hello World!'


@app.route('/api/name/type', methods=["POST"])
def get_type():
    disease_name = request.form['name']
    return jsonify(getDiseaseType(disease_name))


@app.route('/api/name/room', methods=["POST"])
def get_room():
    disease_name = request.form['name']
    return jsonify(getDiseaseRoom(disease_name))


@app.route('/api/query/wd', methods=["POST"])
def query_by_wd():
    question = request.form['question']
    return jsonify({"answer": getCause(question)})


if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True, port=5000)
