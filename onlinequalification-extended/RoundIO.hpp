#ifndef ROUND_IO_HPP_
# define ROUND_IO_HPP_

#include <iostream>
#include <string>
#include "Warehouse.hpp"
#include "drone.hpp"
#include "Product.hpp"

struct RoundIO {

    int nb_rows;
    int nb_columns;
    int nb_drones;
    int nb_turns;
    int nb_max_payload;
    int nb_products;
    int nb_warehouses;
    int nb_orders;
    Drone *drones;
    Product *products;
    Warehouse *warehouses;
    Order *orders;

    RoundIO() {
        std::ios::sync_with_stdio(false);
        std::cin >> nb_rows;
        std::cin >> nb_columns;
        std::cin >> nb_drones;
        std::cin >> nb_turns;
        std::cin >> nb_max_payload;
        drones = new Drone[nb_drones];
        for (int d = 0; d < nb_drones; d++) {
            drones[d].id = d;
            drones[d].row = 0;
            drones[d].column = 0;
            drones[d].turns = nb_turns;
        }
        std::cin >> nb_products;
        products = new Product[nb_products];
        for (int p = 0; p < nb_products; p++) {
            products[p].id = p;
            std::cin >> products[p].weight;
        }
        std::cin >> nb_warehouses;
        warehouses = new Warehouse[nb_warehouses];
        for (int w = 0; w < nb_warehouses; w++) {
            warehouses[w].id = w;
            std::cin >> warehouses[w].row;
            std::cin >> warehouses[w].column;
            warehouses[w].nb_products = new int[nb_products];
            warehouses[w].nb_products_tmp = new int[nb_products];
            for (int wp = 0; wp < nb_products; wp++) {
                std::cin >> warehouses[w].nb_products[wp];
                warehouses[w].nb_products_tmp[wp] = warehouses[w].nb_products[wp];
            }
        }
        std::cin >> nb_orders;
        orders = new Order[nb_orders];
        for (int o = 0; o < nb_orders; o++) {
            orders[o].id = o;
            std::cin >> orders[o].row;
            std::cin >> orders[o].column;
            std::cin >> orders[o].nb_items;
            orders[o].items = new int[orders[o].nb_items];
            for (int oi = 0; oi < orders[o].nb_items; oi++) {
                std::cin >> orders[o].items[oi];
            }
            orders[o].available = 1;
        }
    }
};

extern RoundIO round_io;

#endif /* !ROUND_IO_HPP_ */
