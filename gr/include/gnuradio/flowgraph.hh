#pragma once

#include <gnuradio/graph.hh>

namespace gr {

/**
 * @brief Top level graph representing the flowgraph 
 * 
 */
class flowgraph : public graph
{
public:
    
    typedef std::shared_ptr<flowgraph> sptr;
    static sptr make(const std::string& name = "flowgraph") { return std::make_shared<flowgraph>(name); }
    flowgraph(const std::string& name = "flowgraph");
    virtual ~flowgraph() { };
    static void check_connections(const graph_sptr& g);
};

typedef flowgraph::sptr flowgraph_sptr;
} // namespace gr