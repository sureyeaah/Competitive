void jarvis(Point P[], int n) {
    for(int k = 0; k < n; k++) P[i].extreme = 0;
    int ltl = LTL(P, n), k = ltl;
    do {
        P[k].extreme = 1; int s = -1;
        for(int t = 0; t < n; t++) {
            if(t != k && t != s && 
            (s == -1 || !toLeft(P[k], P[s], P[t])))
                s = t;
        }
        k = s;
    } while( ltl != k);
}
