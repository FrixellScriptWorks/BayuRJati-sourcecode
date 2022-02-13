Attribute VB_Name = "Take_Picture_Pixel_Module"
Private Declare PtrSafe Function SelectObject Lib "gdi32" (ByVal hdc As LongPtr, ByVal hObject As LongPtr) As LongPtr
Private Declare PtrSafe Function CreateCompatibleDC Lib "gdi32" (ByVal hdc As LongPtr) As LongPtr
Private Declare PtrSafe Function DeleteDC Lib "gdi32" (ByVal hdc As LongPtr) As LongPtr
Private Declare PtrSafe Function GetPixel Lib "gdi32" (ByVal hdc As LongPtr, ByVal X As LongPtr, ByVal Y As LongPtr) As LongPtr
Private Function PixelColorBis(objPict As Object, ByVal X As LongPtr, ByVal Y As LongPtr) As LongPtr
 Dim lDC As Variant

 lDC = CreateCompatibleDC(0)
 SelectObject lDC, objPict.Handle
 PixelColorBis = GetPixel(lDC, X, Y)
 DeleteDC lDC
End Function
Function SingleTakePixelColor(Name As String, pixelX As LongPtr, pixelY As LongPtr) As Single
  Dim objPict As Object, pictPath As String, objImage As Object, arrayX As LongPtr, arrayY As LongPtr

  pictPath = ThisWorkbook.Path & "\" & Name & ".jpg" ' use here your picture path
  'Obtain the picture dimensions in pixels______________________________________________________
  Set objImage = CreateObject("WIA.ImageFile")
  On Error GoTo renderFail
  objImage.LoadFile ThisWorkbook.Path & "\" & Name & ".jpg"
  On Error GoTo -1
  'Debug.Print objImage.Width, objImage.Height ' picture dimensions in pixels
  'using the above dimensions you can iterate between the width pixels number and the heigh, too.
  '_____________________________________________________________________________________________

  Set objPict = LoadPicture(pictPath) 'the picture object to be processed

    SingleTakePixelColor = PixelColorBis(objPict, pixelX, pixelY)
  'colorPx = PixelColorBis(objPict, pixelX, pixelY) 'I just used sample X and Y only to check the function functionality
  If colorPx <> 0 Then
  Debug.Print colorPx
  End If
  Exit Function
  
renderFail:
MsgBox "Image Error, please to make sure your file is exist and in the same folder with this workbook.", vbCritical, "Error"
End
End Function
