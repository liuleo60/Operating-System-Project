import numpy
import sys
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
from scipy.stats import norm
from matplotlib.backends.backend_pdf import PdfPages

def main():
    input_path = sys.argv[1];
    data_name = input_path.split('.')[0]
    #output_path = "%s.anlys.txt" % data_name
    figure_path = "%s.pdf" % data_name
    xy_list = []

    prev_line_label = -1
    with open(input_path, 'r') as input_f:
        for line in input_f:
            tokens = line.strip().split('\t')
            line_label = int(tokens[0])
            x = int(tokens[1])
            y = float(tokens[2])
            if line_label != prev_line_label:
                xy_list.append([[], []])
            xy_list[-1][0].append(x)
            xy_list[-1][1].append(y)
            prev_line_label = line_label
    input_f.close()

    print len(xy_list)
    print xy_list
    """
    output_f = open(output_path, 'w')
    output_f.write('Mean: %f\n' % numpy.mean(val_list))
    output_f.write('Std: %f\n' % numpy.std(val_list))
    output_f.close()
    """

    # plot
    pp = PdfPages(figure_path)
    for xy in xy_list:
        plt.plot(xy[0], xy[1], 'k', linewidth=2)
    pp.savefig()
    pp.close()

if __name__ == "__main__":
    main ()
