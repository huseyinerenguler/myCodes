# NAME:     Huseyin Eren Guler
# ID:       15050111014
# Date:     2018/03/23

import xml.etree.ElementTree as ET
import pymysql

"""
# This function drop DATABASE if it already exists.
def dropDATABASE (cursor, databaseName):
    cursor.execute("DROP DATABASE IF EXISTS %s" %(databaseName))

# This function create DATABASE if it not exists.
def createDATABASE (cursor, databaseName):
    cursor.execute("CREATE DATABASE IF NOT EXISTS %s" %(databaseName))

def useDATABASE (cursor, databaseName):
    cursor.execute("USE %s" %(databaseName))
"""

# This function drop TABLE if it already exists.
def dropTABLE (cursor, tableName):
    cursor.execute("DROP TABLE IF EXISTS %s" %(tableName))

# This function create TABLE if it not exists.
def createTABLE (cursor, tableName, SQL):
    cursor.execute("CREATE TABLE IF NOT EXISTS %s (%s)" %(tableName, SQL))

##################################################################
########## PART OF CONNECT TO DATABASE AND CREATE TABLE ##########

database = pymysql.connect("localhost", "testuser", "test123", "TESTDB")
cursor = database.cursor()

#dropDATABASE(cursor, "TESTDB")
#createDATABASE(cursor, "TESTDB")
#useDATABASE(cursor, "TESTDB")

SQL = "ID VARCHAR(20) PRIMARY KEY, NAME VARCHAR(100), AGE INT, GPA FLOAT"

dropTABLE(cursor, "STUDENTS")
createTABLE(cursor, "STUDENTS", SQL)

############################################################
########## PART OF READ XML AND INSERT INTO TABLE ##########

xml_doc = ET.parse("students.xml")
students = xml_doc.getroot()

for student in students:
    try:
        ID = student.attrib["id"]
        NAME = student.find("name").text
        AGE = student.find("age").text
        GPA = student.find("gpa").text

        cursor.execute("INSERT INTO STUDENTS (ID, NAME, AGE, GPA) VALUES (%s,%s,%s,%s)", (ID, NAME, AGE, GPA))
        database.commit()
    except:
        print("ERROR! INSERT INTO STUDENTS WAS FAILED!")

cursor.close()
database.close()

######################################################################
########## PART OF DISPLAY STUDENTS WHO ARE GREATER THAN 20 ##########

database = pymysql.connect("localhost", "testuser", "test123", "TESTDB")
cursor = database.cursor()

cursor.execute("SELECT * FROM STUDENTS WHERE AGE > 20")
results = cursor.fetchall()

print(" ______________________________________________________________")
print("| %13s %25s %8s %8s    |" %("ID", "NAME", "AGE", "GPA"))
for result in results:
    print("| %13s %25s %8s %8.4s    |" %(result[0], result[1], result[2], result[3]))
print("|______________________________________________________________|")