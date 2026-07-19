# helper to generate test data files with fixed seed so results are reproducible
import random
import os

def gen(n, seed, path):
    random.seed(seed)
    lines = [str(n)]
    for i in range(n):
        start = random.randint(0, 100)
        length = random.randint(1, 20)
        finish = start + length
        value = random.randint(1, 100)
        # name like a01, a02, ...
        name = f"a{i+1:03d}"
        lines.append(f"{name} {start} {finish} {value}")
    with open(path, "w") as f:
        f.write("\n".join(lines) + "\n")

if __name__ == "__main__":
    out = os.path.dirname(os.path.abspath(__file__))
    out = os.path.join(out, "..", "data")
    out = os.path.abspath(out)

    # small (brute force can do these)
    gen(10,  1, os.path.join(out, "small_10.txt"))
    gen(15,  2, os.path.join(out, "small_15.txt"))
    gen(20,  3, os.path.join(out, "small_20.txt"))

    # medium (skip brute force)
    gen(50,  4, os.path.join(out, "medium_50.txt"))
    gen(100, 5, os.path.join(out, "medium_100.txt"))
    gen(200, 6, os.path.join(out, "medium_200.txt"))

    # large (greedy vs dp only)
    gen(500,  7, os.path.join(out, "large_500.txt"))
    gen(1000, 8, os.path.join(out, "large_1000.txt"))
    gen(2000, 9, os.path.join(out, "large_2000.txt"))

    print("done.")
