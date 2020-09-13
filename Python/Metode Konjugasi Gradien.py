#================================================================
# Conjugate Gradient Method Script
#
# Author: Bayu R. J. (remove this lol)
# Version: 1.0 *initial release
# Level: Intermediate
# Python : IDLE 3.6.3 (use 'new file' to make a whole script)
#================================================================
# Compatibility
#
# *Function can be seperate independently
#----------------------------------------------------------------
# Known Bugs
#
# *None
#-----------------------------------------------------------------

def createMatrix(rowCount, colCount, dataList): #fungsi bikin matriks multi dimensi
    mat = []
    for i in range(rowCount):
        rowList = []
        for j in range(colCount):
            # you need to increment through dataList here, like this: >> downloaded
            rowList.append(dataList[rowCount * i + j])
        mat.append(rowList)

    return mat # End createMatrix

def transpose_matrix(a): #fungsi transpose matriks
    transposed = [row for row in a]
    
    return transposed # End transpose_matrix

def kalimatrik(a, b): #fungsi kali matriks
    temp = []
    for i in range(0,len(a)):
        s = 0
        for k in range(0,len(b)):
             s += a[i][k] * b[k]
        temp.append(s)
        
    return temp # End kalimatrik

def kalimatrikconst(a, b): #fungsi kali matriks konstanta dengan matriks 1 dimensi (konstanta selalu didepan)
    temp = []
    s = 0
    for k in range(0, len(b)):
        s = a * b[k]
        temp.append(s)
        
    return temp # End kalimatrikconst

def kalimatrik1d(a, b): #fungsi kali matrik 1 dimensi
    s = 0
    temp = []
    for k in range(0,len(a)):
        s += a[k] * b[k]
    temp.append(s)
    
    return temp # End kalimatrik1d

def plusminmatrik(a, b, operand): #fungsi +/- matrix
    if (operand == 0):
        temp = []
        for i in range(0,len(a)):
            temp.append(a[i]+b[i])
    elif (operand == 1):
        temp = []
        for i in range(0,len(a)):
            temp.append(a[i]-b[i])
            
    return temp # End plusminmatrik

def iterasiCG(a, b, jumlah_iterasi): #ini fungsi untuk iterasi
    #Initialization
    r = []
    s = []
    hehe = []
    sT = []
    rT = []
    x = []
    als = []
    j = [0, 0, 0, 0] #matrix x
    x.append(transpose_matrix(j)) #xT

    #Mulai iterasi
    for i in range(0, jumlah_iterasi):
        r.append(plusminmatrik(a, kalimatrik(b, x[i]), 1))

        if (i > 0):
            rT.append(transpose_matrix(r[i]))
            betha = kalimatrik1d(rT[i-1], hehe[i-1])
            bethb = kalimatrik1d(sT[i-1], hehe[i-1])
            bethc = (betha[0]/bethb[0]) - (2 * betha[0]/bethb[0]) 
            s.append(plusminmatrik(r[i], kalimatrikconst(bethc,s[i-1]), 0))
        else:
            s.append(r[i])
            
        hehe.append(kalimatrik(b,s[i]))
        sT.append(transpose_matrix(s[i]))
        alepha = kalimatrik1d(sT[i], r[i])
        alephb = kalimatrik1d(sT[i], hehe[i])
        if(alephb[0] == 0):
            print("Mencapai 0/0")
            break
        else:
            alephc = alepha[0]/alephb[0]
            print("aleph", i, " = ", alephc)
            als.append(kalimatrikconst(alephc, s[i]))
            x.append(plusminmatrik(x[i], als[i], 0))
    print("Kode berhenti di sini")
    return 0 # End iterasiCG

def main():
#===================================
# Konfigurasi Awal
#===================================
    alpha = [200, -50, 0, 0, 50, -125, 75, 0, 0, 75, -300, 225, 0, 0, -225, 225]
    #alpha = [200, -50, 3, 2, 50, -300, 22, 1, 990, 75, -1, 25, 4, 0, -15, 15]
    b = [0, 0, 0, 100]
    A = createMatrix(4, 4, alpha) # row, column, matriks
    
#===================================
# End Konfigurasi
#-----------------------------------
# > Mulai Iterasi
#-----------------------------------
#Inisialisasi Iterasi
    iterasiCG(b, A, 90) # b, A , jumlah iterasi
main()
