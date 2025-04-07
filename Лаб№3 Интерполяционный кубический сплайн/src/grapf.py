import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("output.txt")
x = data[:, 0]
fx = data[:, 1]
s3x = data[:, 2]

plt.figure(figsize=(10, 6))
plt.plot(x, fx, label='f(x) = cos(2x)', color='blue', linewidth=2)
plt.plot(x, s3x, label='S3(x) — Сплайн', color='red', linestyle='--', linewidth=2)
plt.title('Интерполяция f(x) = cos(2x) кубическим сплайном')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("spline_plot.png")

