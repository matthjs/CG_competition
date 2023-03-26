#include "vertex.ih"

Vertex::Vertex(std::initializer_list<float> iniValues)
{
    // A bit messy, but required for code compatibility
    auto itr = iniValues.begin();
    for (size_t cnt = 0; itr != iniValues.end() && cnt != 3; ++cnt)
    {
        d_coords[cnt] = *itr;
        ++itr;
    }

    for (size_t cnt = 0; itr != iniValues.end() && cnt != 3; ++cnt)
    {
        d_normal[cnt] = *itr;
        ++itr;
    }
}