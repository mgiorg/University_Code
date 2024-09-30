from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout

app = QApplication([])

window = QWidget()
window.setWindowTitle("PyQt Example")

layout = QVBoxLayout()

label = QLabel("Hello, PyQt!")
layout.addWidget(label)

window.setLayout(layout)
window.show()

app.exec_()