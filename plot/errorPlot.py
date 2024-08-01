import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


df = pd.read_csv("/Users/imada/2024進捗/8month/program/Simple_and_Kalman_Method/errorCSV/error4.csv") 
column = ["time","Normal","Kalman"]
time = df[column[0]]
normal = df[column[1]]
kalman = df[column[2]]


plt.plot(time, normal, label='normal', color='blue')
plt.plot(time, kalman, label='kalman', color='red')
plt.legend()

plt.xlabel('Time')
plt.ylabel('error')
plt.show()