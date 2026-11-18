"""
plot.py - Ve do thi tu ket qua ngspice (thu muc out/) thanh anh PNG trong out/png/.
Chay sau khi da chay cac file .cir:  python plot.py
Can: python3, numpy, matplotlib  (pip install numpy matplotlib)
"""
import os
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "out")
PNG = os.path.join(OUT, "png")
os.makedirs(PNG, exist_ok=True)

# Bang mau theo thu tu co dinh (khong dao vong)
C = ["#2a78d6", "#eb6834", "#1baf7a", "#eda100", "#e87ba4", "#008300", "#6250d6", "#e34948"]
INK, INK2, GRID = "#0b0b0b", "#52514e", "#e4e3df"

plt.rcParams.update({
    "font.size": 10, "axes.edgecolor": INK2, "axes.labelcolor": INK, "xtick.color": INK2,
    "ytick.color": INK2, "axes.grid": True, "grid.color": GRID, "grid.linewidth": 0.8,
    "axes.spines.top": False, "axes.spines.right": False, "legend.frameon": False,
    "lines.linewidth": 2, "figure.dpi": 150, "savefig.bbox": "tight",
})


CSV = os.path.join(OUT, "csv")


def load(name):
    """Doc file wrdata trong out/csv/ (wr_singlescale + wr_vecnames): cot 0 = thoi gian."""
    return np.loadtxt(os.path.join(CSV, name), skiprows=1)


def table(name):
    """Doc bang .txt (dong dau la tieu de), tra ve list cac dong da tach."""
    with open(os.path.join(OUT, name), encoding="utf-8", errors="replace") as f:
        lines = [l.split() for l in f if l.strip()]
    return lines[1:]


def save(fig, name):
    fig.savefig(os.path.join(PNG, name))
    plt.close(fig)
    print("  da luu out/png/" + name)


# ---------------------------------------------------------------- TIA: chon Cf
def plot_tia_cf():
    rows = table("tia_sweep_cf.txt")
    fig, axes = plt.subplots(1, 3, figsize=(12, 3.6), sharey=True)
    for ax, cj in zip(axes, ["50p", "70p", "120p"]):
        sel = [r for r in rows if r[1] == "0" and r[3] == cj]
        for i, r in enumerate(sel):
            fn = f"tia_cf_{r[0]}.csv"
            if not os.path.exists(os.path.join(CSV, fn)):
                continue
            d = load(fn)
            t = (d[:, 0] - 3e-3) * 1e6
            m = (t >= -10) & (t <= 250)
            ax.plot(t[m], d[m, 1], color=C[i], label=f"Cf = {r[4]} pF ({float(r[6]):.1f}%)")
        ax.set_title(f"Cj = {cj}F", color=INK)
        ax.set_xlabel("Thoi gian sau buoc (us)")
        ax.legend(fontsize=8, loc="lower right")
    axes[0].set_ylabel("V(oa) (V)")
    fig.suptitle("Thang 0 (Rf = 1 MOhm): Cf = 22 pF het vot lo voi moi Cj", color=INK, x=0.01, ha="left", y=1.04)
    save(fig, "tia_cf_thang0.png")


# ------------------------------------------------------ TIA: so sanh mux/Kelvin
def plot_tia_mux():
    rows = table("tia_mux_compare.txt")
    names = {"1": "74HC4052, Kelvin", "2": "74HC4052, khong Kelvin",
             "3": "ADG709, Kelvin", "4": "ADG709, khong Kelvin"}
    fig, (a1, a2) = plt.subplots(1, 2, figsize=(11, 3.6))
    x = np.arange(4)
    w = 0.2
    for j, cfg in enumerate(["1", "2", "3", "4"]):
        sel = sorted([r for r in rows if r[1] == cfg], key=lambda r: int(r[2]))
        vtoi = [float(r[3]) for r in sel]
        err = [float(r[6]) for r in sel]
        a1.bar(x + (j - 1.5) * w, [(v - 0.2057) * 1000 for v in vtoi], w * 0.9, color=C[j], label=names[cfg])
        a2.bar(x + (j - 1.5) * w, err, w * 0.9, color=C[j], label=names[cfg])
    for a in (a1, a2):
        a.set_xticks(x, ["Thang 0\n1 MOhm", "Thang 1\n100 kOhm", "Thang 2\n10 kOhm", "Thang 3\n1 kOhm"])
        a.axhline(0, color=INK2, linewidth=0.8)
    a1.text(3, 40, "ADG709: < 1 mV\no moi thang", ha="center", color=INK2, fontsize=8)
    a1.set_ylabel("Lech diem toi so voi Vref (mV)")
    a1.set_title("Dong ro: lech lon nhat o thang 0", color=INK)
    a2.set_ylabel("Sai so span (%)")
    a2.set_title("Ron: sai so lon nhat o thang 3 khi khong co Kelvin", color=INK)
    a2.legend(fontsize=8, loc="upper left")
    save(fig, "tia_mux_compare.png")


# ------------------------------------------------------------ LED: buoc VSET
def plot_led_step():
    rows = table("led_step.txt")
    fig, axes = plt.subplots(1, 2, figsize=(11, 3.6), sharey=True)
    for ax, vs in zip(axes, ["6.0", "8.4"]):
        sel = [r for r in rows if r[2] == vs]
        for i, r in enumerate(sel):
            d = load(f"led_step_{r[0]}.csv")
            t = (d[:, 0] - 1e-3) * 1e6
            m = (t >= -5) & (t <= 120)
            lab = "khong co C5" if r[1] == "1f" else f"C5 = {r[1]}F"
            ax.plot(t[m], d[m, 1], color=C[i], label=f"{lab} ({float(r[3]):.0f}%)")
        ax.set_title(f"VSYS = {vs} V", color=INK)
        ax.set_xlabel("Thoi gian sau buoc (us)")
        ax.legend(fontsize=8, loc="lower right")
    axes[0].set_ylabel("Dong LED (mA)")
    fig.suptitle("VSET 50 -> 150 mV: C5 = 10 nF het vot lo", color=INK, x=0.01, ha="left", y=1.04)
    save(fig, "led_step.png")


# ------------------------------------------------------------ LED: doi duty
def plot_led_duty():
    d = load("led_duty_step.csv")
    t = (d[:, 0] - 4e-3) * 1e3
    fig, ax = plt.subplots(figsize=(7, 3.4))
    ax.plot(t, d[:, 1], color=C[0])
    ax.set_xlabel("Thoi gian sau khi doi duty 0,2 -> 0,5 (ms)")
    ax.set_ylabel("Dong LED (mA)")
    ax.set_title("Dong LED dat 99% sau ~1,7 ms, nho hon chu ky PI 10 ms", color=INK, loc="left")
    save(fig, "led_duty_step.png")


if __name__ == "__main__":
    for name, fn, need in [("TIA chon Cf", plot_tia_cf, "tia_sweep_cf.txt"),
                           ("TIA so sanh mux", plot_tia_mux, "tia_mux_compare.txt"),
                           ("LED buoc VSET", plot_led_step, "led_step.txt"),
                           ("LED doi duty", plot_led_duty, "csv/led_duty_step.csv")]:
        if os.path.exists(os.path.join(OUT, need)):
            print(name)
            fn()
        else:
            print(f"{name}: chua co out/{need}, bo qua (chay file .cir truoc)")
