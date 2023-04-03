#include "model.ih"

/**
 * @brief Model::Model Constructs a new model from a Wavefront .obj file.
 * @param filename The filename. Should be a .obj file
 */
Model::Model(QString const &filename)
{
    qDebug() << ":: Loading model:" << filename;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        QString line;
        QStringList tokens;

        #pragma omp parallel
        while (!in.atEnd())
        {
            line = in.readLine();
            if (line.startsWith("#"))
                continue;  // skip comments

            tokens = line.split(" ", Qt::SkipEmptyParts);

            // Switch depending on first element
            if (tokens[0] == "v")
                parseVertex(tokens);

            if (tokens[0] == "vn")
                parseNormal(tokens);

            if (tokens[0] == "vt")
                parseTexture(tokens);

            if (tokens[0] == "f")
                parseFace(tokens);
        }

        file.close();

        // create an array version of the data
        unpackIndexes();

        // Allign all vertex indices with the right normal/texturecoord indices
        alignData();
    }
}
