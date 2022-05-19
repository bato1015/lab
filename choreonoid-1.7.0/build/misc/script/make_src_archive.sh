#!/bin/sh

mkdir choreonoid-1.7.0
git archive v1.7.0 | tar -x -C choreonoid-1.7.0
rm choreonoid-1.7.0/.??*
zip -q choreonoid-1.7.0.zip -r choreonoid-1.7.0
rm -fr choreonoid-1.7.0
