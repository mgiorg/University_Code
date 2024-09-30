import wx

app = wx.App(False)
frame = wx.Frame(None, wx.ID_ANY, "Hello wxPython")
panel = wx.Panel(frame)

label = wx.StaticText(panel, label="Hello, wxPython!", pos=(20,20))
frame.Show(True)
app.MainLoop()