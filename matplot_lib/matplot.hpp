#pragma once

#include <cmath>
#include "matplotlibcpp.h"
#include <iostream>

namespace plt = matplotlibcpp;

class MatPlot {
public:
    MatPlot(){};
    ~MatPlot(){};

public:
    template<typename T>
    void PlotDisplay(std::vector<T>& x, std::vector<T>& y, std::string& name);

    template<typename T>
    void PlotDisplay(std::vector<T>& x, std::vector<T>& y, std::vector<T>& z, 
                        std::string& name1, std::string& name2);

    template<typename T>
    void PlotDisplay(std::vector<T>& x, std::vector<T>& y, std::vector<T>& z, 
                        std::vector<T>& p, std::string& name1, std::string& name2, std::string& name3);

    // plot title
    std::string plot_title = "Sample figure";
    // coordinate limit auto?
    bool coordinate_auto = false;
    // set coordinate limit
    int Y_Limit_max = 100;
    int Y_Limit_min = -100;
    int X_Limit_max = 100;
    int X_Limit_min = -100;
    // set plot update rate
    float update_rate = 0.01;

};

template<typename T>
void MatPlot::PlotDisplay(std::vector<T>& x, std::vector<T>& y, std::string& name) {
    // Clear previous plot
    plt::clf();
    // Plot line from given x and y data. Color is selected automatically.
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot(name, x, y);
    // Set axis limit
    if (!coordinate_auto) {
        plt::xlim(X_Limit_min, X_Limit_max);
        plt::ylim(Y_Limit_min, Y_Limit_max);
    }
    // Add graph title
    plt::title(plot_title);
    // Enable legend.
    plt::legend();
    // Display plot continuously
    plt::pause(update_rate);
}

template<typename T>
void MatPlot::PlotDisplay(std::vector<T>& x, std::vector<T>& y, std::vector<T>& z, 
                            std::string& name1, std::string& name2){
    // Clear previous plot
    plt::clf();
    // Plot line from given x and y data. Color is selected automatically.
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot(name1, x, y);
    plt::named_plot(name2, x, z);
    // Set axis limit
    if (!coordinate_auto) {
        plt::xlim(X_Limit_min, X_Limit_max);
        plt::ylim(Y_Limit_min, Y_Limit_max);
    }
    // Add graph title
    plt::title(plot_title);
    // Enable legend.
    plt::legend();
    // Display plot continuously
    plt::pause(update_rate);
}

template<typename T>
void MatPlot::PlotDisplay(std::vector<T>& x, std::vector<T>& y, std::vector<T>& z, std::vector<T>& p, 
                            std::string& name1, std::string& name2, std::string& name3){
    // Clear previous plot
    plt::clf();
    // Plot line from given x and y data. Color is selected automatically.
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot(name1, x, y);
    plt::named_plot(name2, x, z);
    plt::named_plot(name3, x, p);
    // Set axis limit
    if (!coordinate_auto) {
        plt::xlim(X_Limit_min, X_Limit_max);
        plt::ylim(Y_Limit_min, Y_Limit_max);
    }
    // Add graph title
    plt::title(plot_title);
    // Enable legend.
    plt::legend();
    // Display plot continuously
    plt::pause(update_rate);
}