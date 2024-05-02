#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "app/globals.hpp"
#include "entity/map.hpp"

class Operations {
    std::vector<std::function<void()>> _ops;
    std::unordered_map<std::string, size_t> label_map;

   public:
    size_t op_idx;
    Operations();

    void add_op(std::function<void()> const& op);
    void add_label(std::string const& label, size_t idx = -1);
    size_t const& get_label_idx(std::string const& label);

    void set_op_idx(const std::string& label);
    void set_op_idx(size_t idx);
    const std::function<void()>& operator[](size_t idx);
    size_t size();
    void handleClockPulse();
};

struct ParserStatus {
    bool p_err;
    std::string err_msg;
    void error(const std::string& err_msg);
    ParserStatus();
    ParserStatus(bool p_err, std::string err_msg);
};
