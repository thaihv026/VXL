* led_common.inc - Khoi LED: driver dong hang (dung chung cho cac file led_*.cir)
* Node vao: vset, vsys. Tham so: C5
.include models/MCP6001.lib
.include models/irlz44n.spi
.include models/led_1w.lib
V3 vdd3 0 3.3                       ; 3V3A nuoi op-amp
XU2 vset inm vdd3 0 oa MCP6001      ; IN+ = VSET, IN- = phan hoi tu Rs
R8 isense inm 1k                   ; phan hoi
C5 oa inm {C5}                     ; bu tan so (Miller)
R9 oa gate 100                     ; dien tro noi tiep cuc cong
R10 gate 0 100k                    ; giu LED tat khi MCU chua chay
Rser vsys ledA 10                  ; dien tro noi tiep LED 10 ohm / 2 W
D1 ledA drain LEDW                 ; LED trang 1 W
X1 drain gate isense irlz44n       ; IRLZ44N (model Infineon)
Rs isense 0 1                      ; dien tro do dong 1 ohm
R11 isense pa5 10k                 ; loc truoc ADC (PA5)
C11 pa5 0 100n
