* tia_common.inc - Khoi do lux: photodiode + TIA (MCP6001) + 4 thang Rf//Cf
* + mux 2 khoi (force/sense, noi Kelvin) + loc truoc ADC.
* Tham so: k (thang 0..3), RON, ILK (ro moi chan), CSOFF, CJ, KEL (1 = Kelvin),
*           CF0..CF3, ISTEP (dong quang nhay bac tai TSTEP)
.include models/MCP6001.lib
.param RF0=1Meg RF1=100k RF2=10k RF3=1k
.param RK={k==0 ? RF0 : (k==1 ? RF1 : (k==2 ? RF2 : RF3))}

* Nguon 3V3A, Vref (cau chia 30k / 2k)
VDD vdd3 0 3.3
Rv1 vdd3 vref 30k
Rv2 vref 0 2k
Cv  vref 0 100n

* Photodiode: cathode = tia_in, anode = GND (nguon dong + Cj + Rsh)
Iph tia_in 0 PULSE(0 {ISTEP} {TSTEP} 1u 1u 2m 8m)
Cj  tia_in 0 {CJ}
Rsh tia_in 0 1G

* Op-amp: IN+ = vref, IN- = tia_in
XU1 vref tia_in vdd3 0 oa MCP6001

* Mang Rf // Cf
Rf0 tia_in n0 {RF0}
Cf0 tia_in n0 {CF0}
Rf1 tia_in n1 {RF1}
Cf1 tia_in n1 {CF1}
Rf2 tia_in n2 {RF2}
Cf2 tia_in n2 {CF2}
Rf3 tia_in n3 {RF3}
Cf3 tia_in n3 {CF3}

* Mux: khoi force (oa -> nK), khoi sense (nK -> sense), cung chan chon
SF0 oa n0 c0 0 MUXSW
SF1 oa n1 c1 0 MUXSW
SF2 oa n2 c2 0 MUXSW
SF3 oa n3 c3 0 MUXSW
SS0 n0 sense c0 0 MUXSW
SS1 n1 sense c1 0 MUXSW
SS2 n2 sense c2 0 MUXSW
SS3 n3 sense c3 0 MUXSW
Vc0 c0 0 {k==0 ? 3.3 : 0}
Vc1 c1 0 {k==1 ? 3.3 : 0}
Vc2 c2 0 {k==2 ? 3.3 : 0}
Vc3 c3 0 {k==3 ? 3.3 : 0}
.model MUXSW SW(Ron={RON} Roff=100G Vt=1.65 Vh=0.1)

* Dien dung chan cong tac (moi nut S co 2 chan) va dong ro
Cs0 n0 0 {2*CSOFF}
Cs1 n1 0 {2*CSOFF}
Cs2 n2 0 {2*CSOFF}
Cs3 n3 0 {2*CSOFF}
Il0 n0 0 {2*ILK}
Il1 n1 0 {2*ILK}
Il2 n2 0 {2*ILK}
Il3 n3 0 {2*ILK}

* Loc truoc ADC: Kelvin -> ADC doc 'sense'; khong Kelvin -> ADC doc 'oa'
Rsen sense adc {KEL==1 ? 1k : 1T}
Roa  oa    adc {KEL==1 ? 1T : 1k}
Cadc adc 0 100n
