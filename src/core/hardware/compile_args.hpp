#pragma once

#include <sstream>

#include "hardware/parser.hpp"
#include "hardware/program_executor.hpp"

using uchar = unsigned char;
using ulong = unsigned long;

struct DualRegisters;
struct MapEntity;
class Map;
struct ProgramExecutor;
struct Status;
class Inventory;

struct AntInteractor {
    DualRegisters& registers;
    MapEntity& entity;
    Map& map;
    Inventory& inventory;
    std::vector<Op>& ops;
    ushort& op_idx;
    ushort move_speed = 12;
    AntInteractor(DualRegisters& registers, MapEntity& entity, Map& map, Inventory& inventory,
               std::vector<Op>& ops, ushort& op_idx, ushort move_speed): registers(registers), entity(entity),
                map(map), inventory(inventory), ops(ops), op_idx(op_idx), move_speed(move_speed) {}
};

struct CompileArgs {
    std::vector<uchar>::const_iterator code_it;
    AntInteractor& interactor;
    Status& status;
};
