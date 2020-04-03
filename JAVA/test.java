static double Newton_Method_SQRT(double X, int ntimes)
{
    if(ntimes == 0)
        return 1.0;

    double before = Newton_Method_SQRT(X, ntimes-1);
    return before - (before*before - X) / (2*before);
}

static double Newton_Method_CubeRoot(double X, int ntimes)
{
    if(ntimes == 0)
        return 1.0;
    
    double before = Newton_Method_CubeRoot(X, ntimes-1);
    
    
    return before - (before*before*before - X)/(3*before*before);
}