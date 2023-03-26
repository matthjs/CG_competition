#include "model.ih"

/**
 * @brief Model::parseFace Parses a face from the .obj file.
 * @param tokens Tokens on the line in question.
 */
void Model::parseFace(QStringList tokens)
{
    QStringList elements;

    for (int i = 1; i != tokens.size(); ++i)
    {
        elements = tokens[i].split("/");
        // -1 since .obj count from 1
        indices.append(elements[0].toInt() - 1);

        if (elements.size() > 1 && !elements[1].isEmpty())
            texcoord_indices.append(elements[1].toInt() - 1);
        

        if (elements.size() > 2 && !elements[2].isEmpty())
            normal_indices.append(elements[2].toInt() - 1);
    }
}