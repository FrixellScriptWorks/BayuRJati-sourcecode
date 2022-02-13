Attribute VB_Name = "Render_Foto_Module"
Option Explicit
Sub Render_Photo(Name As String, startCell As Range, zoneX As LongPtr, zoneY As LongPtr, Optional preSeq As Integer = 1, Optional currX As LongPtr = 0, Optional currY As LongPtr = 0)
Dim sleepTime As LongPtr, sequences As LongPtr, startCellPlayback As Range, startCellRender As Range
Dim i As LongPtr, j As LongPtr, k As LongPtr
Dim rr As LongPtr, g As LongPtr, b As LongPtr
i = preSeq: j = currX: k = currY
While j < zoneX + 1
    DoEvents
    While k < zoneY + 1
        DoEvents
        If SingleTakePixelColor(Name, j, k) > 16500000 Then
        startCell.Offset(k, j).Interior.Color = RGB(255, 255, 255)
        ElseIf SingleTakePixelColor(Name, j, k) < 263172 Then
        startCell.Offset(k, j).Interior.Color = RGB(0, 0, 0)
        Else
        startCell.Offset(k, j).Interior.Color = SingleTakePixelColor(Name, j, k)
        End If
        k = k + 1
        ThisWorkbook.Sheets("Lembar1").Range("G11").Value = k
    Wend
    j = j + 1
    ThisWorkbook.Sheets("Lembar1").Range("G10").Value = j
    k = 0
Wend
End Sub
