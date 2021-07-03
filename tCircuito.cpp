struct tCircuito{
    double soma_rs(double r1, double r2){
        double reqs;
        reqs = r1 + r2;
        return reqs;
    };

    double soma_rp(double r1, double r2){
        double reqp;
        reqp = 1/(1/r1 + 1/r2);
        return reqp;
    };

    double corrente(double tensao, double resis){
        double i;
        i = tensao/resis;
        return i;
    };

    double potencia(double tensao, double cor){
        double pot;
        pot = tensao*cor;
        return pot;
    };

    double V1;
    double R1;
    double R2;
};
