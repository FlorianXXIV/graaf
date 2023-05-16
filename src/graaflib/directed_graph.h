#pragma once

#include <graaflib/graph.h>

namespace graaf {

    template <typename VERTEX_T, typename EDGE_T>
    class directed_graph final : public graph<VERTEX_T, EDGE_T, GRAPH_SPEC::DIRECTED> {
        private:
            using vertex_id_t = graph<VERTEX_T, EDGE_T, GRAPH_SPEC::DIRECTED>::vertex_id_t;
            using vertex_ids_t = graph<VERTEX_T, EDGE_T, GRAPH_SPEC::DIRECTED>::vertex_ids_t;

			void do_add_edge(vertex_id_t vertex_id_lhs, vertex_id_t vertex_id_rhs, EDGE_T edge) override {
                this->adjacency_list_[vertex_id_lhs].insert(vertex_id_rhs);
                this->edges_.emplace(std::make_pair(vertex_id_lhs, vertex_id_rhs), std::move(edge));
            }

            void do_remove_edge(vertex_id_t vertex_id_lhs, vertex_id_t vertex_id_rhs) override {
                this->adjacency_list_.at(vertex_id_lhs).erase(vertex_id_rhs);
                this->edges_.erase(std::make_pair(vertex_id_lhs, vertex_id_rhs));
            }
    };

}