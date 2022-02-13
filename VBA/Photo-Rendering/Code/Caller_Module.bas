Attribute VB_Name = "Caller_Module"
Sub BWCells()
Dim topLftScr As Range, clrRgn As Range, pictureName As String
Set topLftScr = ThisWorkbook.Sheets("Lembar2").Range("D2")

pictureName = ActiveSheet.Range("G5").Value
If IsEmpty(pictureName) Then
    MsgBox "Please insert picture name.", vbCritical, "Error"
    Exit Sub
End If

Dim scrSqrX As LongPtr, scrSqrY As LongPtr
scrSqrX = ThisWorkbook.Sheets("Lembar1").Range("G3").Value: scrSqrY = ThisWorkbook.Sheets("Lembar1").Range("G4").Value

Set clrRgn = topLftScr.Resize(scrSqrY, scrSqrX)
Call Clear_Cells(clrRgn, scrSqrX, scrSqrY)

ThisWorkbook.Sheets("Lembar2").Activate
clrRgn.RowHeight = 7.5 * 0.5
clrRgn.ColumnWidth = 0.83 * 0.5
ActiveWindow.ScrollRow = 2

Dim borderX As Integer, borderY As Integer
For borderX = 0 To scrSqrX - 1
    topLftScr.Offset(0, borderX).Borders(xlEdgeTop).Color = RGB(0, 0, 0)
    topLftScr.Offset(scrSqrY - 1, borderX).Borders(xlEdgeBottom).Color = RGB(0, 0, 0)
Next borderX
'
For borderY = 0 To scrSqrY - 1
    topLftScr.Offset(borderY, 0).Borders(xlEdgeLeft).Color = RGB(0, 0, 0)
    topLftScr.Offset(borderY, scrSqrX - 1).Borders(xlEdgeRight).Color = RGB(0, 0, 0)
Next borderY
'
clrRgn.Interior.ColorIndex = 0
Application.Windows(1).Zoom = 20
Call Render_Photo(pictureName, topLftScr, scrSqrX, scrSqrY)
End Sub
Sub Resume_Render()
Dim topLftScr As Range, pictureName As String
Set topLftScr = ThisWorkbook.Sheets("Lembar2").Range("D2")
pictureName = ThisWorkbook.Sheets("Lembar1").Range("G5").Value
If IsEmpty(pictureName) Then
    MsgBox "Please insert picture name.", vbCritical, "Error"
    Exit Sub
End If
Dim scrSqrX As LongPtr, scrSqrY As LongPtr
scrSqrX = ThisWorkbook.Sheets("Lembar1").Range("G3").Value: scrSqrY = ThisWorkbook.Sheets("Lembar1").Range("G4").Value
Call Render_Photo(pictureName, topLftScr, scrSqrX, scrSqrY, currX:=ThisWorkbook.Sheets("Lembar1").Range("G10").Value, currY:=ThisWorkbook.Sheets("Lembar1").Range("G11").Value)
End Sub
Sub Stop_Process()
End
End Sub
Sub Clear_Cells(clrRegion As Range, sizeX As LongPtr, sizeY As LongPtr)
clrRegion.Clear
clrRegion.Borders(xlEdgeLeft).LineStyle = xlLineStyleNone
clrRegion.Borders(xlEdgeRight).LineStyle = xlLineStyleNone
clrRegion.Borders(xlEdgeTop).LineStyle = xlLineStyleNone
clrRegion.Borders(xlEdgeBottom).LineStyle = xlLineStyleNone
clrRegion.Borders(xlInsideHorizontal).LineStyle = xlLineStyleNone
clrRegion.Borders(xlInsideVertical).LineStyle = xlLineStyleNone
clrRegion.Borders(xlDiagonalUp).LineStyle = xlLineStyleNone
clrRegion.Borders(xlDiagonalDown).LineStyle = xlLineStyleNone
End Sub

Sub Clear_Cells_No_Border(clrRegion As Range, sizeX As LongPtr, sizeY As LongPtr)
clrRegion.Interior.ColorIndex = 0
End Sub
