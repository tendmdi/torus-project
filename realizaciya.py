import matplotlib.pyplot as plt
x = []
y = []
z = []

with open("points.txt", "r") as f:
    for line in f:
        parts = line.split()
        if len(parts) == 3:
            x.append(float(parts[0]))
            y.append(float(parts[1]))
            z.append(float(parts[2]))

print("Точек загружено:", len(x))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(x, y, z, s=3, c='red')

ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")

ax.set_box_aspect([1,1,1])
plt.show()