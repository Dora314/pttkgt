import time
import numpy as np

# Thuật toán O(n)
def linear_algorithm(n):
    start_time = time.time()
    for i in range(n):
        pass
    end_time = time.time()
    return end_time - start_time

# Thuật toán O(log(n))
def logarithmic_algorithm(n):
    start_time = time.time()
    while n > 1:
        n /= 2
    end_time = time.time()
    return end_time - start_time

# Thuật toán O(n²)
def quadratic_algorithm(n):
    start_time = time.time()
    for i in range(n):
        for j in range(n):
            pass
    end_time = time.time()
    return end_time - start_time

# Chạy thử nghiệm
data_sizes = [10, 100, 1000, 10000, 100000, 1000000]
for n in data_sizes:
    print(f"n = {n}")
    print(f"Thời gian thực thi thuật toán O(n): {linear_algorithm(n)} giây")
    print(f"Thời gian thực thi thuật toán O(log(n)): {logarithmic_algorithm(n)} giây")
    if n <= 10000:  # Chỉ chạy thuật toán O(n²) với n <= 10000 để tránh quá tải
        print(f"Thời gian thực thi thuật toán O(n²): {quadratic_algorithm(n)} giây")
    print("------------------------")
