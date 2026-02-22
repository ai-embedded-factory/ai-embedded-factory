#!/usr/bin/env python3
import csv, sys

REQUIRED_COLS = ["req_id","title","code_ref","test_id","verify_status"]

def main(path: str) -> int:
    with open(path, newline="", encoding="utf-8") as f:
        r = csv.DictReader(f, delimiter=';')
        for c in REQUIRED_COLS:
            if c not in (r.fieldnames or []):
                print(f"ERROR: missing column '{c}'")
                return 2

        ok = True
        for i, row in enumerate(r, start=2):
            req = (row.get("req_id") or "").strip()
            code = (row.get("code_ref") or "").strip()
            tst  = (row.get("test_id") or "").strip()
            st   = (row.get("verify_status") or "").strip()

            if not req:
                print(f"ERROR L{i}: empty req_id")
                ok = False

            if st == "APPROVED" and (not code or not tst):
                print(f"ERROR L{i}: '{req}' APPROVED requires code_ref and test_id")
                ok = False

        return 0 if ok else 1

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("usage: trace_check.py requirements/TRACE_MATRIX.csv")
        raise SystemExit(2)
    raise SystemExit(main(sys.argv[1]))
