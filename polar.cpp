/// Name: polar
/// Description: convert to/from polar coordinates
/// Guarantee: pair<double, double> toCartesian(double r, double phi) {
pair<double, double> toCartesian(double r, double phi) {
    double x = r * cos(phi);
    double y = r * sin(phi);
    return {x, y};
}

pair<double, double> toPolar(double x, double y) {
    double r = sqrt(pow(x, 2) + pow(y, 2));
    double phi = atan2(y, x);
    return {r, phi};
}