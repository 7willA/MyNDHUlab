# quick script to plot results.csv from the c++ program
# i compare greedy / brute force / dp running time and value vs n

import csv, os
import matplotlib.pyplot as plt

here = os.path.dirname(os.path.abspath(__file__))
csv_path = os.path.join(here, "results.csv")

labels = []
ns = []
g_val = []
b_val = []
dp_val = []
g_ms = []
b_ms = []
dp_lin_ms = []
dp_bin_ms = []

with open(csv_path) as f:
    reader = csv.DictReader(f)
    for row in reader:
        labels.append(row["label"])
        ns.append(int(row["n"]))
        g_val.append(int(row["greedy_value"]))
        b_val.append(int(row["brute_value"]))
        dp_val.append(int(row["dp_value"]))
        g_ms.append(float(row["greedy_ms"]))
        b_ms.append(float(row["brute_ms"]))
        dp_lin_ms.append(float(row["dp_linear_ms"]))
        dp_bin_ms.append(float(row["dp_binary_ms"]))

# only use the "experiment" rows (skip example and counterexample) for size scaling
keep = [i for i, l in enumerate(labels) if l not in ("example", "counterexample")]
ns_k = [ns[i] for i in keep]
g_ms_k = [g_ms[i] for i in keep]
b_ms_k = [b_ms[i] for i in keep]
dp_lin_k = [dp_lin_ms[i] for i in keep]
dp_bin_k = [dp_bin_ms[i] for i in keep]
g_val_k = [g_val[i] for i in keep]
dp_val_k = [dp_val[i] for i in keep]

# Chart 1: running time vs n (only sizes where BF measured for BF series)
plt.figure(figsize=(9, 6))
plt.plot(ns_k, g_ms_k,   "o-", label="Greedy")
plt.plot(ns_k, dp_lin_k, "s-", label="DP (linear p)")
plt.plot(ns_k, dp_bin_k, "^-", label="DP (binary p)")
bf_x = [n for n, t in zip(ns_k, b_ms_k) if t >= 0]
bf_y = [t for t in b_ms_k if t >= 0]
plt.plot(bf_x, bf_y, "x-", label="Brute Force", color="red")
plt.xlabel("n (number of activities)")
plt.ylabel("running time (ms)")
plt.title("Lab 6 - Running Time vs n (log scale)")
plt.yscale("log")
plt.xscale("log")
plt.grid(True, which="both", ls=":")
plt.legend()
plt.tight_layout()
plt.savefig(os.path.join(here, "..", "results", "chart_runtime.png"), dpi=120)
plt.close()

# Chart 2: total value greedy vs DP
plt.figure(figsize=(9, 6))
plt.plot(ns_k, g_val_k,  "o-", label="Greedy total value")
plt.plot(ns_k, dp_val_k, "s-", label="DP total value")
plt.xlabel("n (number of activities)")
plt.ylabel("total value of selected activities")
plt.title("Lab 6 - Total Value: Greedy vs DP")
plt.grid(True, ls=":")
plt.legend()
plt.tight_layout()
plt.savefig(os.path.join(here, "..", "results", "chart_value.png"), dpi=120)
plt.close()

# Chart 3: zoom on small n with brute force
small = [i for i, n in enumerate(ns_k) if n <= 20]
plt.figure(figsize=(9, 6))
plt.plot([ns_k[i] for i in small], [g_ms_k[i]   for i in small], "o-", label="Greedy")
plt.plot([ns_k[i] for i in small], [dp_lin_k[i] for i in small], "s-", label="DP (linear p)")
plt.plot([ns_k[i] for i in small], [dp_bin_k[i] for i in small], "^-", label="DP (binary p)")
plt.plot([ns_k[i] for i in small], [b_ms_k[i]   for i in small], "x-", label="Brute Force", color="red")
plt.xlabel("n (number of activities)")
plt.ylabel("running time (ms)")
plt.title("Lab 6 - Brute Force vs the rest (small n, log scale)")
plt.yscale("log")
plt.grid(True, which="both", ls=":")
plt.legend()
plt.tight_layout()
plt.savefig(os.path.join(here, "..", "results", "chart_brute_zoom.png"), dpi=120)
plt.close()

print("charts saved to results/")
