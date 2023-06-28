#                  - OpenPLC Python SubModule (PSM) -
# 
# PSM is the bridge connecting OpenPLC core to Python programs. PSM allows
# you to directly interface OpenPLC IO using Python and even write drivers 
# for expansion boards using just regular Python.
#
# PSM API is quite simple and just has a few functions. When writing your
# own programs, avoid touching on the "__main__" function as this regulates
# how PSM works on the PLC cycle. You can write your own hardware initialization
# code on hardware_init(), and your IO handling code on update_inputs() and
# update_outputs()
#
# To manipulate IOs, just use PSM calls psm.get_var([location name]) to read
# an OpenPLC location and psm.set_var([location name], [value]) to write to
# an OpenPLC location. For example:
#     psm.get_var("QX0.0")
# will read the value of %QX0.0. Also:
#     psm.set_var("IX0.0", True)
# will set %IX0.0 to true.
#
# Below you will find a simple example that uses PSM to switch OpenPLC's
# first digital input (%IX0.0) every second. Also, if the first digital
# output (%QX0.0) is true, PSM will display "QX0.0 is true" on OpenPLC's
# dashboard. Feel free to reuse this skeleton to write whatever you want.

#import all your libraries here
import psm
import time
import socket

HOST = "172.31.94.214"
PORT_ACTUATOR = 65001 
PORT_SENSOR = 65002

#global variables

control_var = 0  #output var to the process
process_var = 0  #input var from the process

actuator_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sensor_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

def hardware_init():
    global actuator_s
    global sensor_s
    conn_act = actuator_s.connect((HOST,PORT_ACTUATOR))
    conn_sen = sensor_s.connect((HOST,PORT_SENSOR))

    #if conn_act == 0:
    #    print("Connected to the Actuator")
    #else:
    #    print("Failed to connect on Actuator")

    #if conn_sen == 0:
    #    print("Connected to the Sensor")
    #else:
    #    print("Failed to connect on Sensor")
    #Insert your hardware initialization code in here
    psm.start()

def update_inputs():
    #place here your code to update inputs
    global sensor_s
    global process_var
    data = sensor_s.recv(1024)
    process_var = data.decode()
    # print("recebido: " + str(process_var))
    psm.set_var("IW0", int(process_var))
    # psm.set_var("QW1", int("3000"))


def update_outputs():
    #place here your code to work on outputs
    global control_var
    control_var = psm.get_var("QW0")
    # print("lido memória: " + str(control_var))
    # actuator_s.sendall(str(control_var).encode())
    actuator_s.sendall(str(control_var).encode())
    # print("enviado " + str(str(control_var).encode()))


if __name__ == "__main__":
    hardware_init()
    while (not psm.should_quit()):
        update_outputs()
        update_inputs()
        time.sleep(0.05) #You can adjust the psm cycle time here
    psm.stop()
