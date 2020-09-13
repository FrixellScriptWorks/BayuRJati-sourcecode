#================================================================
# Black's Principle Iteration (Asas Black) for Figuring Both Latest Temperature with Difference Known
#
# Author: Bayu R. J. (remove this lol)
# Version: 1.0 *initial release
# Level: Beginner
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

suhuXawal = 65
suhuYawal = -25
kalorJenisX = 4200
kalorJenisY = 4200
namaX = "Air"
namaY = "Es"

tipeRumus = 1 #(1 = Turun, 2 = Naik)
selisihXYakhir = 0.8
stepIterasi = 0.2
toleransiSelisih = 0.2 #0 - 1 (0% - 100%)

#Iterasi Asas black
def asasBlack(aX, aY, cX, cY, nX, nY, tR, sXYa, sI, tS): #suhuXawal, suhuYawal, kalorJenisX, kalorJenisY, namaX, namaY, tipeRumus, selisihXYakhir, stepIterasi, toleransiSelisih
    if(tR == 1):
        i = 1
        while True:
            suhuXakhir = (-cY/cX)*(i) + aX
            suhuYakhir = aY + i
            selisihXY = abs(suhuXakhir - suhuYakhir)
            print("T {0} akhir = {1:.2f}\tT {2} akhir = {3:.2f}\t[Selisih = {4:.4f}]".format(nX, suhuXakhir, nY, suhuYakhir, selisihXY))
            i += sI
            if((selisihXY < sXYa + tS * sXYa and selisihXY > sXYa - tS * sXYa) or suhuXakhir < suhuYakhir):
                print("Mencapai batas iterasi atau hasil pendekatan diketahui.")
                break;
    if(tR == 2):
        i = 1
        while True:
            suhuXakhir = (cY/cX) * (i) + aX
            suhuYakhir = aY - i
            selisihXY = abs(suhuXakhir - suhuYakhir)
            print("T {0} akhir = {1:.2f}\tT {2} akhir = {3:.2f}\t[Selisih = {4:.4f}]".format(nX, suhuXakhir, nY, suhuYakhir, selisihXY))
            i += sI
            if((selisihXY < sXYa + tS * sXYa and selisihXY > sXYa - tS * sXYa) or suhuXakhir > suhuYakhir):
                print("Mencapai batas iterasi atau hasil pendekatan diketahui.")
                break;
    
#Call for Function
asasBlack(suhuXawal, suhuYawal, kalorJenisX, kalorJenisY, namaX, namaY, tipeRumus, selisihXYakhir, stepIterasi, toleransiSelisih)
