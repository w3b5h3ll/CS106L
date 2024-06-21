'''
Hey friend! Glad you're curious about this, but please don't touch this file :>)
'''

from csv_utils import *
import os

def main():
  # fstream writing tests!
  binary_to_csv("/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/utils/courses_not_offered.bin", "/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/utils/courses_not_offered.csv")
  binary_to_csv("/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/utils/courses_offered.bin", "/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/utils/courses_offered.csv")
  assert files_are_equal("/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/utils/courses_offered.csv", "/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/student_output/courses_offered.csv"), "write_courses_offered test failed 😞"
  assert files_are_equal("/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/utils/courses_not_offered.csv", "/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/student_output/courses_not_offered.csv"), "write_courses_not_offered test failed 😞"
  # os.remove("/Users/fabio/Desktop/cs106lassignment/simpleenroll/utils/courses_not_offered.csv")
  # os.remove("/Users/fabio/Desktop/cs106lassignment/simpleenroll/utils/courses_offered.csv")
  print("Congratulations, your code passes all the autograder tests! ✅")

main()