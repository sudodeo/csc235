"""
ADESOLA ADEOLUWA
223765
"""
import matplotlib.pyplot as plt


class Terrorist:
    def __init__(self, file_path: str):
        self.file_path = file_path
        self.features_sum = []
        self.similar_ids = []
        self.duplicates = []
        self.all_features = []

    def count_similar_id(self, feature_group, feature_index):
        # this list will hold the indexes of multiple occurences of a
        # feature group in the all_features list
        occurence_index = []
        # checking for the number of times a feature appears
        # in the all_features list
        for index, feature in enumerate(self.all_features):
            if feature == feature_group:
                occurence_index.append(index)

        for o in occurence_index:
            if o == feature_index:
                continue
            else:
                # adding 1
                self.similar_ids.append(o + 1)
                return

        self.similar_ids.append("")

    def count_sum(self, feature_group: list):
        feature_group = [eval(i) for i in feature_group]
        feature_sum = sum(feature_group)
        self.features_sum.append(feature_sum)

    def check_duplicates(self, feature_group):
        feature_count = self.all_features.count(feature_group)
        self.duplicates.append(feature_count - 1)

    def display_output(self, all_features):
        print(
            "{0:10} {1:27} {2:10} {3:15} {4:15}".format(
                "S/N", "Features", "Sum", "Similarity ID", "Duplicate"
            )
        )
        print(
            "_________________________________________________________________________"
        )
        for i in range(len(all_features)):
            current_feature = all_features[i]
            similar_ids = self.similar_ids[i]
            summation = self.features_sum[i]
            duplicate = self.duplicates[i]

            print(
                "|{0:<10} {1:10} {2:10} {3:10} {4:14}".format(
                    i + 1, ", ".join(current_feature), summation, similar_ids, duplicate
                )
            )
            print(
                "_________________________________________________________________________"
            )

    def main(self):
        with open(self.file_path, "r") as file:
            total_feature_groups = int(file.readline())
            for _ in range(total_feature_groups):
                feature_group = file.readline().strip().split(",")
                # apend the feature_group (list) to the all_features list
                self.all_features.append(feature_group)
                # convert the feature group to integers
                feature_group = [eval(i) for i in feature_group]
            for i, feature_group in enumerate(self.all_features):
                self.count_sum(feature_group)
                self.check_duplicates(feature_group)
                self.count_similar_id(feature_group, i)

        self.display_output(self.all_features)

        # plotting the graph
        x_axis = [i + 1 for i in range(total_feature_groups)]
        y_axis = [self.duplicates[i] for i in range(total_feature_groups)]
        _, ax = plt.subplots()
        ax.plot(x_axis, y_axis)

        plt.plot(x_axis, y_axis)

        ax.set_xlabel("program SerialNumbers")
        ax.set_ylabel("program Duplicate")
        ax.set_label("plotting the similarity")

        ax.set_xlim(left=0, right=total_feature_groups + 1)
        ax.set_ylim(bottom=0, top=total_feature_groups + 1)

        plt.show()


# Instantiate the class with the file path
t = Terrorist("terrorist.txt")
t.main()
