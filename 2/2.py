import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

fig, ax = plt.subplots()

# create a rectangle patch
rect = patches.Rectangle((0, 0), 5, 10, angle=0.0)

# add the patch to the axes
ax.add_patch(rect)

# set the limits of the axes
ax.set_xlim(-15, 15)
ax.set_ylim(-15, 15)


# create a function to update the rectangle patch
def update_rect(rect, angle):
    # set the new angle of the rectangle
    rect.angle = angle

    # redraw the figure
    fig.canvas.draw()


# create a loop to rotate the rectangle by 1 degree every iteration
for angle in np.arange(0, 360):
    update_rect(rect, angle)

plt.show()