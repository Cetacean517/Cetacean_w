#!/usr/bin/env python
# -*-coding:utf-8-*-
# @Time: 4/13/2021 4:09 PM
# @File: diseaseClassify.py
# @Author: Chasing
# @Email: chasing1020@gmail.com
# @Software: PyCharm


import json

disease_type = ()
with open("data/data_json.json", encoding="utf-8") as f:
    data = json.load(f)


def getDiseaseRoom(disease_name):
    possible_rooms_name_list = []
    for i in data.get("data"):
        for j in i.get("sub_room"):
            flag = False
            for k in j.get("room_disease").get("disease_name"):
                if disease_name in k:
                    flag = True
            if flag:
                possible_rooms_name_list.append(j.get("room_name"))
    return {"possible_rooms": possible_rooms_name_list}


def getDiseaseType(disease_name):
    possible_types_list = []
    for i in data.get("data"):
        for j in i.get("sub_room"):
            index = 0
            flag = False
            for k in j.get("room_disease").get("disease_name"):
                if disease_name in k:
                    flag = True
                    break
                index += 1
            if flag:
                possible_types_list.append(j.get("room_disease").get("disease_type")[index])
    return {"possible_types": possible_types_list}


if __name__ == '__main__':
    symptom = "感冒"
    print(getDiseaseRoom(symptom))
    print(getDiseaseType(symptom))
