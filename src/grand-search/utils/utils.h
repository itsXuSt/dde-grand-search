/*
 * Copyright (C) 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     houchengqiu<houchengqiu@uniontech.com>
 *
 * Maintainer: wangchunlin<wangchunlin@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SORTMATCHITEM_H
#define SORTMATCHITEM_H

#include "global/matcheditem.h"

class Utils
{
public:

    // 排序算法 用于搜索结果排序 规则为：中文 > 英文 > 其他语言 > 标点符号
    static bool sort(GrandSearch::MatchedItems &list, Qt::SortOrder order = Qt::AscendingOrder);

    static bool compareByString(const QString &str1, const QString &str2, Qt::SortOrder order = Qt::AscendingOrder);
    static bool startWithSymbol(const QString &text);
    static bool startWithHanzi(const QString &text);
    static bool startWithLatin(const QString &text);
    static bool startWithOtherLang(const QString &text);

    // 获取搜索结果默认打开应用图标
    static QString appIconName(const GrandSearch::MatchedItem &item);
    // 根据文件路径获取mimetype
    static QString getFileMimetype(const QString &filePath);
    // 通过Gio接口获取mimeType
    static QString getFileMimetypeByGio(const QString &path);
    // 通过Qt接口获取mimeType
    static QString getFileMimetypeByQt(const QString &path);
    // 根据mimeType获取默认打开应用路径
    static QString getDefaultAppDesktopFileByMimeType(const QString &mimeType);
    // 搜索结果是否来自内置搜索项
    static bool isResultFromBuiltSearch(const GrandSearch::MatchedItem &item);
    // 打开搜索结果项
    static bool openMatchedItem(const GrandSearch::MatchedItem &item);
    // 打开对应路径下的应用/文件/文件夹
    static bool openFile(const QString &filePath);
    // 启动应用，若filePaths不为空，则用该应用打开传入的文件, 否则，仅启动应用
    static bool launchApp(const QString& desktopFile, const QStringList &filePaths = {});
    // 使用Dbus启动应用
    static bool launchAppByDBus(const QString &desktopFile, const QStringList &filePaths = {});
    // 使用gio启动应用
    static bool launchAppByGio(const QString &desktopFile, const QStringList &filePaths = {});

private:
    static QMap<QString, QString> m_appIconNameMap;// 存放应用desktop文件对应的图标名称，用于搜索框应用图标刷新
    static QMimeDatabase m_mimeDb;
};

#endif // SORTMATCHITEM_H