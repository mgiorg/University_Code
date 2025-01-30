param lato_tri := 1;

var l >= 0;  # Lato del quadrato

maximize AreaQuadrato: l^2;

subject to VincoloTriangoloQuad:
    l <= lato_tri / sqrt(2);