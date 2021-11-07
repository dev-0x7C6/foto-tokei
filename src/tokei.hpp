#pragma once

#include <QAbstractListModel>
#include <optional>

namespace model {

struct entry {
	QString name;
	QString url;
};

using entries = std::vector<entry>;

class tokei final : public QAbstractListModel {
	Q_OBJECT
public:
	virtual ~tokei() final = default;

	enum Role {
		Name = Qt::UserRole,
	};

	int rowCount(const QModelIndex &parent) const final;
	QVariant data(const QModelIndex &index, int role) const final;
	QHash<int, QByteArray> roleNames() const final;

	void setEntries(entries &&);

	std::optional<entry> selected();
	std::optional<entry> mixed();

	Q_INVOKABLE void setCurrentIndex(int index);

signals:
	void imageReady(const QString &);

private:
	int m_currentIndex{0};
	std::size_t m_mixIndex{0};
	entries m_entries;
};

} // namespace model
