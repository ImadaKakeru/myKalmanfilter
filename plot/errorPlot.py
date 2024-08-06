import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# データの読み込み
df = pd.read_csv("/Users/imada/2024進捗/8month/program/Simple_and_Kalman_Method/errorCSV/error4.csv")
column = ["time", "Normal", "Kalman"]
time = df[column[0]]
normal = df[column[1]]
kalman = df[column[2]]

# 10個ずつ平均を取る関数
def batch_average(data, window_size):
    return data.groupby(data.index // window_size).mean()

# ウィンドウサイズ
window_size = 10

# 10個ずつ平均を計算
time_avg = batch_average(time, window_size)
normal_avg = batch_average(normal, window_size)
kalman_avg = batch_average(kalman, window_size)

# プロット
plt.scatter(time_avg, normal_avg, label='normal (10-mean)', color='blue')
plt.scatter(time_avg, kalman_avg, label='kalman (10-mean)', color='red')
plt.legend()

plt.xlabel('Time')
plt.ylabel('Error')
plt.title('10-mean Averaged Errors')
plt.show()
