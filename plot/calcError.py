import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# データの読み込み
df = pd.read_csv("/Users/imada/2024進捗/8month/program/Simple_and_Kalman_Method/errorCSV/error6.csv")
column = ["time","Normal","Kalman"]
time = df[column[0]]
normal = df[column[1]]
kalman = df[column[2]]

print("kalman error = ",kalman[20:].mean(), "+-" , kalman[20:].std())
print("normal error = ",normal[20:].mean(), "+-" , normal[20:].std())
plt.legend()

plt.plot(time, kalman, label="kalman", color='red')
plt.plot(time, normal, label="normal", color='blue')
plt.xlabel('Time')
plt.ylabel('Error')
plt.title('10-mean Averaged Errors')
plt.show()
