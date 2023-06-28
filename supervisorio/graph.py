from pyModbusTCP.client import ModbusClient
import datetime as dt
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pickle
import time

IP = '54.91.136.118'

try:
    c = ModbusClient(host=IP, port=502)
except ValueError:
    print("Error with host or port params")

# Create figure for plotting
fig = plt.figure()
fig2 = plt.figure()
ax = fig.add_subplot(1, 1, 1)
bx = fig2.add_subplot(1, 1, 1)
ax.set_ylim(0, 300)
bx.set_ylim(0, 300)
plt.style.use("seaborn")
xs = []
ys = []

SAVE_LIST = list()


# This function is called periodically from FuncAnimation
def animate(i, xs, ys):
    # Read temperature (Celsius) from TMP102
    temp_c = c.read_input_registers(0)

    # Add x and y to lists
    xs.append(dt.datetime.now().strftime('%M:%S.0%f'))
    try:
        ys.append(temp_c[0] * 300 / 6000)
    except:
        try:
            ys.append(ys[49])
        except:
            ys.append(0)
    # Limit x and y lists to 20 items
    xs = xs[-50:]
    ys = ys[-50:]

    # Draw x and y lists
    ax.clear()
    ax.plot(xs, ys)
    bx.clear()
    try:
        bx.bar(['nivel'], [temp_c[0] * 300 / 6000])
    except:
        bx.bar(['nivel'], [0])

    # Format plot
    plt.xticks(rotation=45, ha='right')
    plt.subplots_adjust(bottom=0.30)
    plt.title('Nivel')
    plt.ylabel('(mL)')
    plt.xlabel('(s)')

    try:
        file = open('State', 'rb')
        state = pickle.load(file)
        file.close()
        global SAVE_LIST
        if state == 'True':
            SAVE_LIST.append([xs[0], ys[0]])
            file = open('Graph', 'wb')
            pickle.dump(SAVE_LIST, file)
            file.close()
    except:
        pass


def animate2(i):
    # Read temperature (Celsius) from TMP102
    temp_c = c.read_input_registers(0)
    bx.clear()
    try:
        bx.bar(['nivel'], [temp_c[0] * 300 / 6000])
    except:
        bx.bar(['nivel'], [0])

    # Format plot
    plt.xticks(rotation=45, ha='right')
    plt.subplots_adjust(bottom=0.30)
    plt.title('Nivel')
    plt.ylabel('(mL)')
    plt.xlabel('(s)')


if __name__ == '__main__':
    # Set up plot to call animate() function periodically
    ani = animation.FuncAnimation(fig, animate, fargs=(xs, ys), interval=200)
    ani2 = animation.FuncAnimation(fig2, animate2, fargs=(), interval=600)
    plt.show()
