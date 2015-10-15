import numpy
import sys
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
from scipy.stats import norm
from matplotlib.backends.backend_pdf import PdfPages

def main():
    input_path = sys.argv[1];
    data_name = input_path.split('.')[0]
    output_path = "%s.anlys.txt" % data_name
    figure_path = "%s.pdf" % data_name
    val_list = []

    with open(input_path, 'r') as input_f:
        for line in input_f:
            val_list.append(float(line.strip()))
    input_f.close()

    output_f = open(output_path, 'w')
    output_f.write('Mean: %f\n' % numpy.mean(val_list))
    output_f.write('Std: %f\n' % numpy.std(val_list))
    output_f.close()

    # plot
    # Create a normal distribution
    mu, std = norm.fit(val_list)
    # Plot the histogram
    plt.hist(val_list, bins=100, normed=True, alpha=0.6)
    # Plot the distribution
    xmin, xmax = plt.xlim()
    x = numpy.linspace(xmin, xmax, 100)
    p = norm.pdf(x, mu, std)

    pp = PdfPages(figure_path)
    plt.plot(x, p, 'k', linewidth=2)
    pp.savefig()
    pp.close()

if __name__ == "__main__":
    main ()
