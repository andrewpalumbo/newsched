/* -*- c++ -*- */
/*
 * Copyright 2004,2009,2012,2013 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#pragma once

#include <gnuradio/blocks/head.h>

namespace gr {
namespace blocks {

class head_cpu : public head
{
public:
    head_cpu(const block_args& args);
    virtual work_return_code_t
    work(std::vector<block_work_input_sptr>& work_input,
         std::vector<block_work_output_sptr>& work_output) override;

private:
    size_t d_nitems;
    size_t d_ncopied_items = 0;
};

} // namespace blocks
} // namespace gr