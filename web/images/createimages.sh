convert -size 100x100 xc:transparent -fill darkgrey -draw 'rectangle 10,0 90,100' centerv.png
convert -size 100x100 xc:transparent -fill darkgrey -draw 'rectangle 0,10 100,90' centerh.png
convert -size 100x100 xc:transparent water.png
#convert -size 100x100 xc:transparent -fill darkgrey -draw "circle 50,0 50,50"  down.png
convert -size 100x100 xc:transparent -fill darkgrey -draw "circle 50,50 90,50" -fill darkgrey -draw 'rectangle 10,0 90,50' down.png
convert -size 100x100 xc:transparent -fill darkgrey -draw "circle 50,50 90,50" sub.png
convert -rotate 90 down.png left.png
convert -rotate -90 down.png right.png
convert -rotate 180 down.png up.png
for EACH in centerv centerh down left right up sub water
do
	filename=$EACH.png
	convert -resize 30x30 $EACH.png $EACH'_small.png'
done
