import math
import csv
import PySimpleGUI as sg
from pyModbusTCP.client import ModbusClient
import pickle

IP = '54.91.136.118'

layout = [
    [sg.Text('Gráfico em Tempo Real'), ],
    [sg.Text("Setpoint:", size=(10, 1)), sg.In(size=(25, 1), key="-SP-"), sg.Button('Set', key='SetP'), ],
    [sg.Text("TR:", size=(10, 1)), sg.In(default_text="2500", size=(25, 1), key="-TR-"),
     sg.Button('Set', key='SetTR'), ],
    [sg.Text("Kp:", size=(10, 1)), sg.In(default_text="1700", size=(25, 1), key="-KP-"),
     sg.Button('Set', key='SetKP'), ],
    [sg.OptionMenu(values=('Aberto', 'Fechado'), default_value='Aberto', key='-State-'), ],
    [sg.Button('StartSave', key='-Start-'), sg.Button('EndSave', key='-Stop-'), sg.Text('...', key='-SST-'), ],
]

window = sg.Window('Supervisório', layout)

try:
    c = ModbusClient(host=IP, port=502)
except ValueError:
    print("Error with host or port params")


if __name__ == '__main__':
    while True:
        event, values = window.read()

        if event == sg.WINDOW_CLOSED or event == 'Sair':
            break
        if event == 'SetP':
            SP = int(values["-SP-"])
            c.write_single_register(1, math.floor(SP * 6000 / 300))

            if values['-State-'] == 'Aberto':
                c.write_single_coil(0, 1)
            elif values['-State-'] == 'Fechado':
                c.write_single_coil(0, 0)

        if event == 'SetTR':
            TR = int(values['-TR-'])
            c.write_single_register(3, math.floor(TR))
        if event == 'SetKP':
            KP = int(values['-KP-'])
            c.write_single_register(2, math.floor(KP))

        if event == '-Start-':
            window["-SST-"].update("Salvando...")
            file = open('State', 'wb')
            pickle.dump('True', file)
            file.close()

        elif event == '-Stop-':
            window["-SST-"].update("Salvo")
            file = open('State', 'wb')
            pickle.dump('False', file)
            file.close()

            header = ['Time', 'Nivel']

            with open('Graph.csv', 'w', encoding='UTF8', newline='') as f:
                try:
                    file = open('Graph', 'rb')
                    SAVE_LIST = pickle.load(file)
                    file.close()
                    writer = csv.writer(f)
                    writer.writerow(header)
                    writer.writerows(SAVE_LIST)

                    SAVE_LIST = list()
                except:
                    pass
