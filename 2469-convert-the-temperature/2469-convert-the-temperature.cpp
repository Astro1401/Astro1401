class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;

        double fh = ( celsius * 1.8 ) + 32.00;

        return{kelvin,fh};
    }
};