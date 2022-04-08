/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/kernel/digital/constellation.h>

#define D(...) ""
void bind_constellation(py::module& m)
{

    using constellation = ::gr::kernel::digital::constellation;
    using constellation_calcdist = ::gr::kernel::digital::constellation_calcdist;
    using constellation_sector = ::gr::kernel::digital::constellation_sector;
    using constellation_rect = ::gr::kernel::digital::constellation_rect;
    using constellation_expl_rect = ::gr::kernel::digital::constellation_expl_rect;
    using constellation_psk = ::gr::kernel::digital::constellation_psk;
    using constellation_bpsk = ::gr::kernel::digital::constellation_bpsk;
    using constellation_qpsk = ::gr::kernel::digital::constellation_qpsk;
    using constellation_dqpsk = ::gr::kernel::digital::constellation_dqpsk;
    using constellation_8psk = ::gr::kernel::digital::constellation_8psk;
    using constellation_8psk_natural = ::gr::kernel::digital::constellation_8psk_natural;
    using constellation_16qam = ::gr::kernel::digital::constellation_16qam;

    py::class_<constellation, std::shared_ptr<constellation>> constellation_class(
        m, "constellation", D(constellation));

    py::enum_<constellation::normalization_t>(constellation_class, "normalization")
        .value("NO_NORMALIZATION", constellation::NO_NORMALIZATION)
        .value("POWER_NORMALIZATION", constellation::POWER_NORMALIZATION)
        .value("AMPLITUDE_NORMALIZATION", constellation::AMPLITUDE_NORMALIZATION)
        .export_values();

    py::implicitly_convertible<int, gr::kernel::digital::constellation::normalization_t>();

    constellation_class
        .def("map_to_points",
             &constellation::map_to_points,
             py::arg("value"),
             py::arg("points"),
             D(constellation, map_to_points))


        .def("map_to_points_v",
             &constellation::map_to_points_v,
             py::arg("value"),
             D(constellation, map_to_points_v))


        .def("decision_maker",
             &constellation::decision_maker,
             py::arg("sample"),
             D(constellation, decision_maker))


        .def("decision_maker_v",
             &constellation::decision_maker_v,
             py::arg("sample"),
             D(constellation, decision_maker_v))


        .def("decision_maker_pe",
             &constellation::decision_maker_pe,
             py::arg("sample"),
             py::arg("phase_error"),
             D(constellation, decision_maker_pe))


        .def("calc_metric",
             &constellation::calc_metric,
             py::arg("sample"),
             py::arg("metric"),
             py::arg("type"),
             D(constellation, calc_metric))


        .def("calc_euclidean_metric",
             &constellation::calc_euclidean_metric,
             py::arg("sample"),
             py::arg("metric"),
             D(constellation, calc_euclidean_metric))


        .def("calc_hard_symbol_metric",
             &constellation::calc_hard_symbol_metric,
             py::arg("sample"),
             py::arg("metric"),
             D(constellation, calc_hard_symbol_metric))


        .def("points", &constellation::points, D(constellation, points))


        .def("s_points", &constellation::s_points, D(constellation, s_points))


        .def("v_points", &constellation::v_points, D(constellation, v_points))


        .def("apply_pre_diff_code",
             &constellation::apply_pre_diff_code,
             D(constellation, apply_pre_diff_code))


        .def("set_pre_diff_code",
             &constellation::set_pre_diff_code,
             py::arg("a"),
             D(constellation, set_pre_diff_code))


        .def("pre_diff_code",
             &constellation::pre_diff_code,
             D(constellation, pre_diff_code))


        .def("rotational_symmetry",
             &constellation::rotational_symmetry,
             D(constellation, rotational_symmetry))


        .def("dimensionality",
             &constellation::dimensionality,
             D(constellation, dimensionality))


        .def("bits_per_symbol",
             &constellation::bits_per_symbol,
             D(constellation, bits_per_symbol))


        .def("arity", &constellation::arity, D(constellation, arity))


        .def("base", &constellation::base, D(constellation, base))


     //    .def("as_pmt", &constellation::as_pmt, D(constellation, as_pmt))


        .def("gen_soft_dec_lut",
             &constellation::gen_soft_dec_lut,
             py::arg("precision"),
             py::arg("npwr") = 1.,
             D(constellation, gen_soft_dec_lut))


        .def("calc_soft_dec",
             &constellation::calc_soft_dec,
             py::arg("sample"),
             py::arg("npwr") = 1.,
             D(constellation, calc_soft_dec))


        .def("set_soft_dec_lut",
             &constellation::set_soft_dec_lut,
             py::arg("soft_dec_lut"),
             py::arg("precision"),
             D(constellation, set_soft_dec_lut))


        .def("has_soft_dec_lut",
             &constellation::has_soft_dec_lut,
             D(constellation, has_soft_dec_lut))


        .def("soft_dec_lut", &constellation::soft_dec_lut, D(constellation, soft_dec_lut))


        .def("soft_decision_maker",
             &constellation::soft_decision_maker,
             py::arg("sample"),
             D(constellation, soft_decision_maker))

        ;


    py::class_<constellation_calcdist,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_calcdist>>(
        m, "constellation_calcdist", D(constellation_calcdist))

        .def(py::init(&constellation_calcdist::make),
             py::arg("constell"),
             py::arg("pre_diff_code"),
             py::arg("rotational_symmetry"),
             py::arg("dimensionality"),
             py::arg("normalization") = constellation::AMPLITUDE_NORMALIZATION,
             D(constellation_calcdist, make))


        .def("decision_maker",
             &constellation_calcdist::decision_maker,
             py::arg("sample"),
             D(constellation_calcdist, decision_maker))

        ;


    py::class_<constellation_sector,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_sector>>(
        m, "constellation_sector", D(constellation_sector))

        .def("decision_maker",
             &constellation_sector::decision_maker,
             py::arg("sample"),
             D(constellation_sector, decision_maker))

        ;


    py::class_<constellation_rect,
               gr::kernel::digital::constellation_sector,
               std::shared_ptr<constellation_rect>>(
        m, "constellation_rect", D(constellation_rect))

        .def(py::init(&constellation_rect::make),
             py::arg("constell"),
             py::arg("pre_diff_code"),
             py::arg("rotational_symmetry"),
             py::arg("real_sectors"),
             py::arg("imag_sectors"),
             py::arg("width_real_sectors"),
             py::arg("width_imag_sectors"),
             py::arg("normalization") = constellation::AMPLITUDE_NORMALIZATION,
             D(constellation_rect, make));


    py::class_<constellation_expl_rect,
               gr::kernel::digital::constellation_rect,
               std::shared_ptr<constellation_expl_rect>>(
        m, "constellation_expl_rect", D(constellation_expl_rect))

        .def(py::init(&constellation_expl_rect::make),
             py::arg("constellation"),
             py::arg("pre_diff_code"),
             py::arg("rotational_symmetry"),
             py::arg("real_sectors"),
             py::arg("imag_sectors"),
             py::arg("width_real_sectors"),
             py::arg("width_imag_sectors"),
             py::arg("sector_values"),
             D(constellation_expl_rect, make));


    py::class_<constellation_psk,
               gr::kernel::digital::constellation_sector,
               std::shared_ptr<constellation_psk>>(
        m, "constellation_psk", D(constellation_psk))

        .def(py::init(&constellation_psk::make),
             py::arg("constell"),
             py::arg("pre_diff_code"),
             py::arg("n_sectors"),
             D(constellation_psk, make));


    py::class_<constellation_bpsk,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_bpsk>>(
        m, "constellation_bpsk", D(constellation_bpsk))

        .def(py::init(&constellation_bpsk::make), D(constellation_bpsk, make))


        .def("decision_maker",
             &constellation_bpsk::decision_maker,
             py::arg("sample"),
             D(constellation_bpsk, decision_maker));


    py::class_<constellation_qpsk,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_qpsk>>(
        m, "constellation_qpsk", D(constellation_qpsk))

        .def(py::init(&constellation_qpsk::make), D(constellation_qpsk, make))


        .def("decision_maker",
             &constellation_qpsk::decision_maker,
             py::arg("sample"),
             D(constellation_qpsk, decision_maker));


    py::class_<constellation_dqpsk,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_dqpsk>>(
        m, "constellation_dqpsk", D(constellation_dqpsk))

        .def(py::init(&constellation_dqpsk::make), D(constellation_dqpsk, make))


        .def("decision_maker",
             &constellation_dqpsk::decision_maker,
             py::arg("sample"),
             D(constellation_dqpsk, decision_maker));


    py::class_<constellation_8psk,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_8psk>>(
        m, "constellation_8psk", D(constellation_8psk))

        .def(py::init(&constellation_8psk::make), D(constellation_8psk, make))


        .def("decision_maker",
             &constellation_8psk::decision_maker,
             py::arg("sample"),
             D(constellation_8psk, decision_maker));


    py::class_<constellation_8psk_natural,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_8psk_natural>>(
        m, "constellation_8psk_natural", D(constellation_8psk_natural))

        .def(py::init(&constellation_8psk_natural::make),
             D(constellation_8psk_natural, make))


        .def("decision_maker",
             &constellation_8psk_natural::decision_maker,
             py::arg("sample"),
             D(constellation_8psk_natural, decision_maker));


    py::class_<constellation_16qam,
               gr::kernel::digital::constellation,
               std::shared_ptr<constellation_16qam>>(
        m, "constellation_16qam", D(constellation_16qam))

        .def(py::init(&constellation_16qam::make), D(constellation_16qam, make))


        .def("decision_maker",
             &constellation_16qam::decision_maker,
             py::arg("sample"),
             D(constellation_16qam, decision_maker));
}